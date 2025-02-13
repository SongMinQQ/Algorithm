import java.io.*;
import java.util.*;

public class Main {
    static int n, d, k, c, result;
    static int[] check = new int[3002];

    static int getMaxResult() {
        int cnt = 0;
        for (int i = 1; i <= d; i++) {
            if (check[i] > 0) cnt++;
        }
        return cnt;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        
        int[] sushi = new int[n];
        for (int i = 0; i < n; i++) {
            sushi[i] = Integer.parseInt(br.readLine());
        }
        
        for (int i = 0; i < k; i++) {
            check[sushi[i]]++;
            result = Math.max(result, getMaxResult());
            check[c]++;
        }
        int checker = result;
        
        for (int i = 0; i < n; i++) {
            int nextIndex = (i + k) % n;
            if (check[sushi[nextIndex]] == 0) {
                check[sushi[nextIndex]]++;
                checker++;
            } else if (check[sushi[nextIndex]] > 0) {
                check[sushi[nextIndex]]++;
            }
            check[sushi[i]]--;
            if (check[sushi[i]] == 0) {
                checker--;
            }
            if (check[c] == 0) {
                result = Math.max(result, checker + 1);
            } else {
                result = Math.max(result, checker);
            }
        }
        System.out.println(result);
    }
}
