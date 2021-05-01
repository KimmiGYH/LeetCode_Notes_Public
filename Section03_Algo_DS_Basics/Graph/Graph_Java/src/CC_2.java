// CC_2.java，将visited数组改成int让它可以承载更多信息，
// 进而不仅可以求出整张图中又多少个联通分量，还可以求出每个联通分量中都包含哪些顶点或者指定的某两个顶点是否相连
import java.util.ArrayList;

public class CC_2 { // CC = connected component

    private Graph G;
    private int[] visited;
    private int ccount = 0;

    public CC_2(Graph G) {//构造函数
        this.G = G;
        visited = new int[G.V()];
        for (int i = 0; i < visited.length; i ++)
            visited[i] = -1;
        for (int v = 0; v < G.V(); v ++)
            if (visited[v] == -1) {
                dfs(v, ccount);
                ccount ++;
            }
    }

    private void dfs(int v, int ccid) {
        visited[v] = ccid;
        for (int w: G.adj(v))
            if (visited[w] == -1)
                dfs(w, ccid);
    }

    public int count() {
        for (int e: visited)
            System.out.print(e + " ");
        System.out.println();
        return ccount;
    }
    
    public boolean isConnected(int v, int w) {
        G.validateVertex(v);
        G.validateVertex(w);
        return visited[v] == visited[w];
    }

    //看整张图有多少个联通分量，每个联通分量中都包含哪些顶点
    public ArrayList<Integer>[] components() {
        ArrayList<Integer>[] res = new ArrayList[ccount];
        for (int i = 0; i < ccount; i ++)
            res[i] = new ArrayList<>();
        
        //填充res信息，可以遍历图中所有顶点，对于每个顶点，联通分量所对应的id的值就存在visited的v中
        for (int v = 0; v < G.V(); v ++)
            res[visited[v]].add(v);
        return res;
    }

    public static void main(String[] args) {
        Graph g = new Graph("D:/GitHub/GitHub_code/LeetCode_Notes_Public/Section03_Algo_DS_Basics/Graph/Graph_Java/g.txt");
        CC_2 cc = new CC_2(g);
        System.out.println(cc.count());

        System.out.println(cc.isConnected(0, 6)); //0和6联通
        System.out.println(cc.isConnected(0, 5)); //0和5不联通

        ArrayList<Integer>[] comp = cc.components();
        for (int ccid = 0; ccid < comp.length; ccid ++) {
            System.out.print(ccid + " : ");
            for (int w: comp[ccid]) //comp[ccid]存储了某个联通分量里的所有顶点
                System.out.print(w + " ");
            System.out.println();
        }
    }
}

/** 输出：
0 0 0 0 0 1 0   
2
true
false
0 : 0 1 2 3 4 6 
1 : 5


**联通分量的id，只有5号节点的id是1，与其他不同
0 0 0 0 0 1 0 

**整张图中有多少个联通分量
2

**求出指定的某两个顶点是否相连，如看0与6和5分别是否联通
true
false

**每个联通分量中都包含哪些顶点
0 : 0 1 2 3 4 6 
1 : 5
*/