import queue
adj_list={
     "a":["b","c"],
     "b":["d","e"],
     "c":["f","g"],
     "d":["h","i"],
     "e":[],
     "f":["j"],
     "g":[],
     "h":[],
     "i":[],
     "j":[]
     }
visited=[]
queue=[]
bfsoutput=[]

def bfs(visited,graph,node):
     visited.append(node)
     queue.append(node)
     while(queue):
          m=queue.pop(0)
          bfsoutput.append(m)

          for neighbour in graph[m]:
               if neighbour not in visited:
                    visited.append(neighbour)
                    queue.append(neighbour)

                    
     print("bfs traversing output is=",bfsoutput)
print("bfs output")
rootnode=input("Enter the root node=")
bfs(visited,adj_list,rootnode)