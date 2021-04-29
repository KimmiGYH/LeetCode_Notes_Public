import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner; //为了读进来File

public class AdjList_ {

    private int V;
    private int E;
    private LinkedList<Integer>[] adj;

    public AdjList_(String filename) {

        File file = new File(filename);

        try(Scanner scanner = new Scanner(file)) {
            V = scanner.nextInt();
            if (V < 0) throw new IllegalArgumentException("V must be non-negative");
            adj = new LinkedList[V]; //先申请整个数组的内存空间
            for (int i = 0; i < V; i ++) //之后对于数组中的每个元素再分别申请它们的内存空间
                adj[i] = new LinkedList<Integer>();

            E = scanner.nextInt();
            if (E < 0) throw new IllegalArgumentException("E must be non-negative");
            for (int i = 0; i < E; i ++) {
                int a = scanner.nextInt();
                validateVertex(a);
                int b = scanner.nextInt();
                validateVertex(b);

                if (a == b) throw new IllegalArgumentException("Self Loop is Detected!"); //处理自环边
                //判断 adj[a]这个链表中是否包含有 b 这个顶点
                if (adj[a].contains(b)) throw new IllegalArgumentException("Parallel Edges are Detected!"); //处理平行边
                
                adj[a].add(b);
                adj[b].add(a);
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void validateVertex(int v) {
        if ( v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is invalid");
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public boolean hasEdge(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        return adj[v].contains(w);
    }

    public LinkedList<Integer> adj(int  v) { //返回和v相邻的所有顶点

        validateVertex(v);        
        return adj[v];
    }

    public int degree(int v) { //点的邻边数量
        return adj(v).size();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(String.format("V = %d, E = %d\n", V, E));
        for (int v = 0; v < V; v ++) {
            sb.append(String.format("%d : ", v));
            for (int w: adj[v])
                sb.append(String.format("%d ", w));
            sb.append('\n');
        }
        return sb.toString();
    }

    public static void main(String[] args) {

        AdjList_ adjList = new AdjList_("g.txt");
        System.out.print(adjList);
    }
}

/*输出：
V = 7, E = 9  
0 1 0 1 0 0 0 
1 0 1 0 0 0 1 
0 1 0 1 0 1 0 
1 0 1 0 1 0 0 
0 0 0 1 0 1 0 
0 0 1 0 1 0 1 
0 1 0 0 0 1 0
*/