# -*- coding: utf-8 -*-
"""
Created on Wed Oct 27 20:27:47 2021

@author: Divyabrata
"""
import random as rnd

loc={'0':'1','1':'02','2':'13','3':'2'}

class WumpusWorld:
    
    def __init__(self):
        self.board=[]
        for i in range(4):
            self.board.append([])
            for j in range(4):
                self.board[i].append(set([i+j]))
    def boardSet(self):
        self.board[0][0].add('Start')
        self.board[0][0].add('OK')
        print('This is 4 X 4 wumpus world board, please enter location of the following entities: ')
        ch=input('Enter location of Gold in the form row,column: ').split(',')
        self.board[int(ch[0])][int(ch[1])].add('Gold')
        ch=input('Enter location of Wumpus in the form row,column: ').split(',')
        self.board[int(ch[0])][int(ch[1])].add('Wumpus')
        for i in loc[ch[0]]:
            self.board[int(i)][int(ch[1])].add('S')
        for j in loc[ch[1]]:
            self.board[int(ch[0])][int(j)].add('S')
        n=int(input('Enter number of pits: '))
        for i in range(1,n+1):
            ch=input('Enter location of {}th pit in the form row,column: '.format(i)).split(',')    
            self.board[int(ch[0])][int(ch[1])].add('Pit')
            for i in loc[ch[0]]:
                self.board[int(i)][int(ch[1])].add('B')
            for j in loc[ch[1]]:
                self.board[int(ch[0])][int(j)].add('B')

class Agent:
    def __init__(self):
        self.percieve=[]
        self.arrow=1
        self.i=0
        self.j=0
        self.agentBoard=[]
        for i in range(4):
            self.agentBoard.append([])
            for j in range(4):
                self.agentBoard[i].append(set([i+j]))
    def checkWumpus(self):
        p,q,c,x,y='','',0,0,0
        for i in loc[str(self.i)]:
            if 'S' in self.agentBoard[int(i)][self.j]:
                p=i
                q=str(self.j)
                break
        else:
            for j in loc[str(self.j)]:
                if 'S' in self.agentBoard[self.i][int(j)]:
                    p=str(self.i)
                    q=j
                    break
        if p!='' and q!='':
            for i in loc[p]:
                if 'W?' in self.agentBoard[int(i)][int(q)]:
                    c+=1
                    y=int(i)
                    x=int(q)
            for j in loc[q]:
                if 'W?' in self.agentBoard[int(p)][int(j)]:
                    c+=1
                    y=int(p)
                    x=int(j)
        if c==1:
            self.agentBoard[y][x].discard('W?')
            self.agentBoard[y][x].add('W!')
    def checkPit(self):
        p,q,c,x,y='','',0,0,0
        for i in loc[str(self.i)]:
            if 'B' in self.agentBoard[int(i)][self.j]:
                p=i
                q=str(self.j)
                break
        else:
            for j in loc[str(self.j)]:
                if 'B' in self.agentBoard[self.i][int(j)]:
                    p=str(self.i)
                    q=j
                    break
        if p!='' and q!='':
            for i in loc[p]:
                if 'P?' in self.agentBoard[int(i)][int(q)]:
                    c+=1
                    y=int(i)
                    x=int(q)
            for j in loc[q]:
                if 'P?' in self.agentBoard[int(p)][int(j)]:
                    c+=1
                    y=int(p)
                    x=int(j)
        if c==1:
            self.agentBoard[y][x].discard('P?')
            self.agentBoard[y][x].add('P!')
    def percieveCheck(self):
        flag=0
        if 'Gold' in self.percieve:
            self.agentBoard[self.i][self.j].add('GOLD')
            return 'Goal Reached'
        if 'S' in self.percieve:
            flag=1
            self.agentBoard[self.i][self.j].add('S')
            for i in loc[str(self.i)]:
                if '~W' not in self.agentBoard[int(i)][self.j]:
                    self.agentBoard[int(i)][self.j].add('W?')
            for j in loc[str(self.j)]:
                if '~W' not in self.agentBoard[self.i][int(j)]:
                    self.agentBoard[self.i][int(j)].add('W?')
        else:
            for i in loc[str(self.i)]:
                self.agentBoard[int(i)][self.j].discard('W?')
                self.agentBoard[int(i)][self.j].add('~W')
                self.checkWumpus()
                if '~P' in self.agentBoard[int(i)][self.j]:
                    self.agentBoard[int(i)][self.j].add('OK')
            for j in loc[str(self.j)]:
                self.agentBoard[self.i][int(j)].discard('W?')
                self.agentBoard[self.i][int(j)].add('~W')
                self.checkWumpus()
                if '~P' in self.agentBoard[self.i][int(j)]:
                    self.agentBoard[self.i][int(j)].add('OK')
        if 'B' in self.percieve:
            flag=1
            self.agentBoard[self.i][self.j].add('B')
            for i in loc[str(self.i)]:
                if '~P' not in self.agentBoard[int(i)][self.j]:
                    self.agentBoard[int(i)][self.j].add('P?')
            for j in loc[str(self.j)]:
                if '~P' not in self.agentBoard[self.i][int(j)]:
                    self.agentBoard[self.i][int(j)].add('P?')
        else:
            for i in loc[str(self.i)]:
                self.agentBoard[int(i)][self.j].discard('P?')
                self.agentBoard[int(i)][self.j].add('~P')
                self.checkPit()
                if '~W' in self.agentBoard[int(i)][self.j]:
                    self.agentBoard[int(i)][self.j].add('OK')
            for j in loc[str(self.j)]:
                self.agentBoard[self.i][int(j)].add('~P')
                self.agentBoard[self.i][int(j)].discard('P?')
                self.checkPit()
                if '~W' in self.agentBoard[self.i][int(j)]:
                    self.agentBoard[self.i][int(j)].add('OK')
        if flag==0:
            for i in loc[str(self.i)]:
                if 'OK' not in self.agentBoard[int(i)][self.j]:
                    self.agentBoard[int(i)][self.j].discard('P?')
                    self.agentBoard[int(i)][self.j].discard('W?')
                    self.agentBoard[int(i)][self.j].add('OK')
            for j in loc[str(self.j)]:
                if 'OK' not in self.agentBoard[self.i][int(j)]:
                    self.agentBoard[self.i][int(j)].discard('P?')
                    self.agentBoard[self.i][int(j)].discard('W?')
                    self.agentBoard[self.i][int(j)].add('OK')
        return ''     
    def gameMove(self):
        obj=WumpusWorld()
        obj.boardSet()
        for p in range(3,-1,-1):
            for q in range(4):
                st=''
                for i in obj.board[p][q]:
                    if isinstance(i, str):
                        st+=' '+i+' '
                if st=='':
                    st='R'
                print('|{0:^14}|'.format(st),end=' ')
            print()
        print('\n\n')
        self.agentBoard[0][0].add('OK')
        while True:
            for i in obj.board[self.i][self.j]:
                self.percieve.append(i)
            res=self.percieveCheck()
            for p in range(3,-1,-1):
                for q in range(4):
                    st=''
                    for i in self.agentBoard[p][q]:
                        if isinstance(i, str):
                            st+=' '+i+' '
                    if p==self.i and q==self.j:
                        st+=' A '
                    if st=='':
                        st='?'
                    print('|{0:^21}|'.format(st),end=' ')
                print()
            print('\n\n')
            if res=='Goal Reached':
                print(res)
                break
            visLst=[]
            okLst=[]
            for i in loc[str(self.i)]:
                if 'V' in self.agentBoard[int(i)][self.j]:
                    visLst.append([int(i),self.j])
                elif 'OK' in self.agentBoard[int(i)][self.j]:
                    okLst.append([int(i),self.j])
            for j in loc[str(self.j)]:
                if 'V' in self.agentBoard[self.i][int(j)]:
                    visLst.append([self.i,int(j)])
                elif 'OK' in self.agentBoard[self.i][int(j)]:
                    okLst.append([self.i,int(j)])
            c=0
            if len(okLst)>0:
                c=rnd.choice(okLst)
            else:
                c=rnd.choice(visLst)
            self.agentBoard[self.i][self.j].add('V')
            self.percieve.clear()
            self.i=c[0]
            self.j=c[1]
                
                
if __name__=='__main__':
    obj=Agent()
    obj.gameMove()
