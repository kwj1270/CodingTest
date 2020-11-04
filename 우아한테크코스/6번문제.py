import datetime

totalTicket = 2000
logs = [
    "woni request 09:12:29",
    "brown request 09:23:11",
    "brown leave 09:23:44",
    "jason request 09:33:51",
    "jun request 09:33:56",
    "cu request 09:34:02"
]

def solution(totalTicket, logs):
    answer = []
    
    sess = SessStat()
    
    minTime = datetime.datetime.strptime("09:00:00","%H:%M:%S")
    maxTime = datetime.datetime.strptime("10:00:00","%H:%M:%S")
    
    for i in logs:
        
        lst = i.split(' ')        
        logTime = datetime.datetime.strptime(lst[2],"%H:%M:%S")
        
        if lst[1] == 'request':
            if sess.log =='request' and sess.time + datetime.timedelta(minutes=1) < logTime:
                sess.time = logTime
                answer.append(sess.man)
                
            if sess.stat == False and \
                (minTime<=logTime and logTime<=maxTime) :
                sess.req(logTime)
                sess.time = logTime
                sess.man = lst[0]
        else:
            #if logTime sess.time:
            if totalTicket>0 and sess.time + datetime.timedelta(minutes=1) < logTime:
                totalTicket-=0
                print(lst[0])
                sess.time = logTime
                answer.append(lst[0])

            sess.lev(logTime)
            sess.man = None
        
    if sess.log == 'request' and sess.time + datetime.timedelta(minutes=1)< datetime.datetime.strptime('10:00:00', '%H:%M:%S'):
        answer.append(sess.man)
        
    return answer

class SessStat:
    stat = False
    time = None
    log = None
    man = None

    def req(self, req):
        self.log = 'request'
        self.time = req
        self.stat = True
    def lev(self, lev):
        self.log = 'leave'
        self.time = lev
        self.stat = False

print(solution(totalTicket, logs))
    
