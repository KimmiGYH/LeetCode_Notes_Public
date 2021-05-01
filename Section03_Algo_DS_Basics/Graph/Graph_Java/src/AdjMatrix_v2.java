import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner; //为了读进来File

public class AdjMatrix_v2 {

    private int V;
    private int E;
    private int[][] adj;

    public AdjMatrix_v2(String filename) {

        File file = new File(filename);

        try(Scanner scanner = new Scanner(file)) {
            V = scanner.nextInt();
            if (V < 0) throw new IllegalArgumentException("V must be non-negative");
            adj = new int[V][V]; //创建二维数组

            E = scanner.nextInt();
            if (E < 0) throw new IllegalArgumentException("E must be non-negative");
            for (int i = 0; i < E; i ++) {
                int a = scanner.nextInt();
                validateVertex(a);
                int b = scanner.nextInt();
                validateVertex(b);

                if (a == b) throw new IllegalArgumentException("Self Loop is Detected!"); //处理自环边
                if (adj[a][b] == 1) throw new IllegalArgumentException("Parallel Edges are Detected!"); //处理平行边
                
                adj[a][b] = 1;
                adj[b][a] = 1;
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
        return adj[v][w] == 1;
    }

    public ArrayList<Integer> adj(int v) { //返回和v相邻的所有顶点

        validateVertex(v);        
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i ++)
            if (adj[v][i] == 1)
                res.add(i);
        return res;
    }

    public int degree(int v) { //点的邻边数量
        return adj(v).size();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(String.format("V = %d, E = %d\n", V, E));
        for (int i = 0; i < V; i ++) {
            for (int j = 0; j < V; j ++)
                sb.append(String.format("%d ", adj[i][j]));
            sb.append('\n');
        }
        return sb.toString();
    }

    public static void main(String[] args) {

        AdjMatrix_v2 adjMatrix = new AdjMatrix_v2("g.txt");
        System.out.print(adjMatrix);
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