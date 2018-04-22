import random
import time

windowS = []
timeout = 0
index_frame_send = 0
sent_frame = 0
isAckOnHold = False
isFrameArriveAtPL = False
isAckReceived = False
isError = False


class frame:
    seq_no = 0

    def __init__(self, data):
        frame.seq_no += 1
        self.data = data
        self.ack_no = -1
        self.acknowledgment_recieved = False


PL_data = frame(-1)


def wait_for_event():
    if (isFrameArriveAtPL):
        return "frame_arr"


def wait_for_event_S():
    global isAckReceived, isAckOnHold, isError
    if (isAckReceived):
        isAckReceived = False
        return "ack"
    elif (isAckOnHold):
        isAckOnHold = False
        return "hold"
    elif (isError):
        isError = False
        return "hold"


def from_NL():
    data = int(random.random() * 10)
    return data


def to_PL(s):
    global PL_data, isFrameArriveAtPL
    PL_data = s
    isFrameArriveAtPL = True


def to_PL_R(s):
    global PL_data, isAckOnHold, isAckReceived, isError
    PL_data = s
    ch = int(random.random() * 10)
    if (ch <= 4):
        isAckReceived = True
    elif (ch >= 7):
        isAckOnHold = True
    elif (ch == 5 or ch == 6):
        isError = True


def from_PL():
    if (isFrameArriveAtPL):
        return PL_data


def to_NL(I):
    print("\n\n\nData going to sent : ", I)


def ack_checker():
    for i in range(0, len(windowS)):
        if (windowS[i].acknowledgment_recieved == False):
            return i
def acknowledge_frame(sent_frame):
    for i in range (0,sent_frame):
        windowS[i].acknowledgment_recieved = True

def sender():
    global sent_frame, index_frame_send, timeout
    ch = int(random.random() * 20)
    if (ch < 8):
        timeout = 1
    else:
        timeout = 0

    if (sent_frame == 0):
        to_PL(windowS[index_frame_send])
        sent_frame += 1
        index_frame_send += 1

    else:
        event = wait_for_event_S()
        if (timeout == 0):
            if (event == "ack"):
                print("Acknowledgment Recieved for ", sent_frame,
                      "\n----------------------------------------------------------------------------------")
                acknowledge_frame(sent_frame)
                windowS[index_frame_send - 1].acknowledgment_recieved = True
                to_PL(windowS[index_frame_send])
                sent_frame += 1
                index_frame_send += 1

            elif (event == 'hold'):
                windowS[index_frame_send - 1].acknowledgment_recieved = False
                to_PL(windowS[index_frame_send])
                sent_frame += 1
                index_frame_send += 1

            elif (event == "error"):
                print("Negative Acknowledgment Recieved")
                print("Sending Frame ", sent_frame, " again")
                to_PL(windowS[index_frame_send - 1])

        else:
            sent_frame = ack_checker()
            index_frame_send = sent_frame
            print("\n\n\n--------------------------------------------\nAcknowledgment Lost for Frame ", sent_frame + 1)
            print("Sending Frame ", sent_frame + 1, " again")
            to_PL(windowS[index_frame_send])
            sent_frame += 1
            index_frame_send += 1


def reciever():
    global isError
    r = frame(-1)
    s = frame(-1)
    ch = int(random.random() * 100)
    event = wait_for_event()
    if (event == "frame_arr"):
        r = from_PL()
        to_NL(r.data)
        if (ch < 60):
            s.ack_no = r.seq_no
            to_PL_R(s)
        else:
            isError = True


frame_nos = int(input("Enter the windows size : "))
for i in range(0, frame_nos):
    windowS.append(frame(from_NL()))

print(windowS[0].data)

for i in range(0, frame_nos * 2):
    sender()
    time.sleep(2)
    reciever()