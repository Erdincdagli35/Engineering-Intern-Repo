package bfs;

/**
 *
 * @author Erdinç Dağlı
 */
class Node {
    int label;Node next;
    Node (int b){label=b;}
}
class Queue{
    private int maxSize;
    private int front;
    private int rear;
    private int count;
    private int [] que;
    public Queue(int s)
    {
        maxSize=s;que =new int[maxSize];
        front=rear=-1;
    }
    public void qinsert(int item )
    {
        if (rear==maxSize-1) {
            System.out.print("Queue is Full \n");
            
        }if (front==-1) {
                front=0;
            }
        else{
            rear=rear+1;
            que[rear]=item;
            
        }
        
    }
    public int qdelete(){
        int item;
        if (IsEmpty()) {System.out.print("\n Queue is Empty ");return (-1);}
        
        item=que[front];
        if (front==rear) front =rear=-1;
            
                    
        
        else front=front+1;return item;
    }
    
    
    public boolean IsEmpty()
    {
        return (front==-1);
    }
} 
   
    

class Graph
{
    int size,mark[]; Node adjList[];
    Graph(int n )
    {
        size =n;
        adjList=new Node [size];
        mark=new int[size];
    }
    public void creatAdjList(int a[][])
    {
        Node p;int i,k;
        for (i = 0; i < size; i++) {
            p=adjList[i]=new Node(i);
            for ( k = 0; k < size; k++) {
                if (a[i][k]==1) {
                    p.next= new Node(k);
                    p=p.next;
                }
            }
        }
    }
    public void dfs(int head){
        Node w;int v;
        mark[head]=1;
        System.out.println(head+" ");
        w=adjList[head];
        while(w!=null)
        {
            v=w.label;
            if (mark[v]==0) {
                dfs(v);
                
            }w=w.next;
        }
    }
}
class BfSGraph{
    int size,mark[]; Node adjList[];
    BfSGraph(int n )
    {
        size =n;
        adjList=new Node [size];
        mark=new int[size];
    }
    public void createAdjList(int a[][])
    {
        Node p;int k,i;
        for (i = 0; i < size; i++) {
            p=adjList[i]=new Node(i);
            for (k = 0; k < size; k++) {
                if (a[i][k]==1) {
                    p.next=new Node(k);
                    p=p.next;
                }
            }
        }
    }
    public void bfs(int head )
    {
        int v;Node adj;
        Queue q =new Queue(size);
        v=head;mark[v]=1;
        System.out.println(v+"");
        q.qinsert(v);
        while(!q.IsEmpty())
        {
            v=q.qdelete();adj=adjList[v];
            while(adj!=null)
            {
                v=adj.label;
                if (mark[v]==0) {
                    q.qinsert(v);
                    mark[v]=1;System.out.print(v+"");
                }
                adj=adj.next;
            }
        }
    }
    
}
public class BFS {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //DFS
        /*Graph g=new Graph(5);
        int a[][]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,0},{1,0,1,0,0}};
        g.creatAdjList(a);
        g.dfs(0);*/
        //BFS
       BfSGraph g =new BfSGraph(5);
       int a[][]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,0},{1,0,1,0,0}};
       g.createAdjList(a);g.bfs(0);
    }
    
}
