import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static LinkedList<Integer>[] graph;
	static boolean[] visited;
	static int N, M;
	static boolean result = false;
	public static void main(String[] args) throws IOException {
		String[] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		
		graph = new LinkedList[N];
		
		for(int i = 0; i < N; i++) {
			graph[i] = new LinkedList<Integer>();
		}
		
		
		for(int i = 0; i < M; i++) {
			String[] nodes = br.readLine().split(" ");
			int node1 = Integer.parseInt(nodes[0]);
			int node2 = Integer.parseInt(nodes[1]);
			graph[node1].add(node2);
			graph[node2].add(node1);
		}
		
		for(int i = 0; i < N; i++) {
			visited = new boolean[N];
			dfs(i, 1); 
            if(result){
				System.out.println(1);
				return;
			}
		}
		
		System.out.println(0);
	}
	
	static void dfs(int start, int count) {
        if(count == 5) {
			result = true;
            return;
		}
		visited[start] = true;
		for(int nextNode: graph[start]) {
			if(!visited[nextNode]) {
				dfs(nextNode, count + 1);
			}
		}
		visited[start] = false;
	}
}