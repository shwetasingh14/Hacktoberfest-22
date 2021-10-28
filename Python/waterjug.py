# -*- coding: utf-8 -*-
"""
Created on Thu Aug 26 21:15:25 2021

@author: Divyabrata
"""
import sys
from collections import deque
queue=deque()
explored=[]
maxState,goalState=[],[]
f=0
maxState.append(int(input('Enter max capacity of first Jug(in gallons): ')))
maxState.append(int(input('Enter max capacity of second Jug(in gallons): ')))

goalState.append(int(input('Enter goal or target capacity you want in first Jug(in gallons): ')))
goalState.append(int(input('Enter goal or target capacity you want in second Jug(in gallons): ')))

if maxState[0]<goalState[0] or maxState[1]<goalState[1]:
    print('Given goal is not possible to achieve')
    sys.exit()

lst=[goalState[0],goalState[1]]

def recur(State):
    global f
    if State==goalState:
        print('Goal Reached at {} simulation'.format(len(explored)+1))
        print("The queue of States explored to find the goal state is as follows: ")
        for i in explored:
            print(i,'->',end='')
        print(State)
        explored.append(State)
        f=1
        return
    explored.append(State)
    if State[0]<maxState[0]:
        temp=[maxState[0],State[1]]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if State[1]<maxState[1]:
        temp=[State[0],maxState[1]]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if State[0]>0:
        temp=[0,State[1]]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if State[1]>0:
        temp=[State[0],0]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if sum(State)>=maxState[1]:
        temp=[sum(State)-maxState[1],maxState[1]]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    else:
        temp=[0,sum(State)]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if sum(State)>=maxState[0]:
        temp=[maxState[0],sum(State)-maxState[0]]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    else:
        temp=[sum(State),0]
        if temp not in explored and temp not in queue:
            queue.append(temp)
    if f==0:
        try:
            flag=recur(queue.popleft())
        except Exception as e:
            print('Not Found')

def disp():
    global lst
    i=len(explored)-1
    k=i-1
    while i!=0:
        State=explored[k]
        if [maxState[0],State[1]]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [State[0],maxState[1]]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [0,State[1]]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [State[0],0]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [sum(State)-maxState[1],maxState[1]]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [0,sum(State)]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [maxState[0],sum(State)-maxState[0]]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        elif [sum(State),0]==explored[i]:
            i=k
            k-=1
            lst=State+lst
            continue
        else:
            k-=1
            continue
    print('Shortest path to the goal state {} from root state [0, 0] is as follows:'.format(goalState))
    for i in range(0,len(lst)-1,2):
        print('[{},{}]'.format(lst[i],lst[i+1]),end='->')
    print('GOAL')
recur([0,0])
disp()
