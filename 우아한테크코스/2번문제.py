# 문제 소개
'''
# 분양된 땅
lands = [[10,0,30,5], [0,30,20,50],[30,30,40,40]]
# 식수지
wells = [[15,15,25,25],[40,10,50,20]]
# 분양하려는 땅
point = [10,10,30,30]

2차원 평면에 직사각형 으로 이루어진 좌표 List 가 있다

[10,0,30,5] 라는 좌표가 주어졌으면

왼쪽 아래 좌표는 [10,0] 오른쪽 위 좌표는 [30, 5] 가 된다.

분양하려는 땅(point)의 조건은 식수지를 조금이라도 포함하여야 되며,
분양된 땅과 면적이 곂치지 않아야 된다.

point의 조건이 만족한다면 true, 그렇지 않으면 false 를 return 하라
'''
def solution(lands, wells, point):
    # return 하려는 boolean 변수
    answer = True
    
    # cmpLands 는 밑에서 정의한 함수 (return type List)
    # parameter(분양된 땅(lands), 분양할 땅(point))
    # 만약 cmpLands의 return list 값들 중에 False 가 있으면
    # 분양할 수 없으므로 False를 return 한다.
    # 그렇지 않으면 분양 조건 중 하나를 만족하므로 다음으로 넘어간다.
    if False in cmpLands(lands, point):
        return False
    

    # wellsLands 는 밑에서 정의한 함수 (return type List)
    # parameter(식수지 정보(wells), 분양할 땅(point))
    # 만약 wellsLands의 return list 값들 중에 True 가 있으면
    # 식수지를 포함하므로 return True
    # 그렇지 않으면 조건을 만족하지 않으므로 return False
    if True in wellsLands(wells, point):
        return True
    else:
        return False


def cmpLands(lands, point):
    lst = []
    for i in lands:
        # 분양될 수 없는 땅의 조건은
        #  lands x좌표 최소값 <= x <= lands x 좌표 최대값
        #  lands y좌표 최소값 <= y <= lands y 좌표 최대값 이므로
        #  이 조건에 포함된다면 False를 return 한다.
        if (i[0]<=point[0] and i[2]>=point[0]) \
            and (i[0]<=point[2] and i[2]>=point[2]) \
            and (i[1]<=point[1] and i[3]>=point[1]) \
            and (i[1]<=point[3] and i[3]>=point[3]):
            # 조건을 만족하면 더 이상 볼필요 없으므로 break 하여 반복을 빠져나온다.
            lst.append(False)
            break
    return lst      
            
def wellsLands(wells, point):
    lst = []
    for i in wells:
        # 분양될 땅의 조건은 식수지를 조금이라도 포함되어야 하므로
        # 좌표 중 하나만 point 안에 들어오면 된다.
        if (i[0]>=point[0] and i[0]<=point[3]) \
            or (i[3]>=point[0] and i[3]<=point[3]) \
            or (i[1]>=point[1] and i[1]<=point[3]) \
            or (i[3]>=point[1] and i[3]<=point[3]):
            lst.append(True)
            break

    return lst


# 분양된 땅
lands = [[10,0,30,5], [0,30,20,50],[30,30,40,40]]
# 식수지
wells = [[15,15,25,25],[40,10,50,20]]
# 분양하려는 땅
point = [10,10,30,30]

print(solution(lands,wells, point))
