# 양승열
time = 0
# 입력부
n, w, L = map(int, input().split())
truck = list(map(int, input().split()))
bridge = [0] * w
bridge_load = 0

# bridge를 모두 0으로 세팅한 후 시간의 흐름에 따라 계속 가장 앞에 것(다리 완전 건넌것)을 pop
# 하중에서 건넌것 무게 빼주기
# 현재 하중 + 다리에 올라갈 트럭무게 <= 최대하중 이면 다리위에 트럭올라감
# 중요! pop을 먼저하면안됌. 한타이밍에 빠져나가면서 올라오는건 불가능!!
# 다리위에 트럭못올라가면 다리에 0 append 하여 1 in 1 out 구조 유지
while True:
    time += 1
    cross_end = bridge.pop(0)
    bridge_load -= cross_end

    if truck:
        if bridge_load + truck[0] <= L:
            bridge.append(truck[0])
            bridge_load += truck[0]
            truck.pop(0)
        else:
            bridge.append(0)
    if not bridge:
        print(time)
        break
