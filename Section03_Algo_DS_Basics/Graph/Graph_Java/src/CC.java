public class CC { // CC = connected component

    private Graph G;
    private boolean[] visited;
    private int ccount = 0;

    public CC(Graph G) {//构造函数
        this.G = G;
        visited = new boolean[G.V()];
        // dfs(0); 这步需改进
        for (int v = 0; v < G.V(); v ++)
            if (!visited[v]) {
                dfs(v);
                ccount ++;
            }
    }

    private void dfs(int v) {
        visited[v] = true;
        for (int w: G.adj(v))
            if (!visited[w]) dfs(w);
    }

    public int count() {
        return ccount;
    }
    
    public static void main(String[] args) {
        Graph g = new Graph("D:/GitHub/GitHub_code/LeetCode_Notes_Public/Section03_Algo_DS_Basics/Graph/Graph_Java/g.txt");
        CC cc = new CC(g);
        System.out.println(cc.count());
    }
}
/* 输出：2 */