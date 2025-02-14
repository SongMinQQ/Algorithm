import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();

        Deque<Integer> dq = new ArrayDeque<>(n);
        for(int i = 0; i < n; i++){
            dq.add(i + 1);
        }
        List<Integer> v = new LinkedList<>();

        while(!dq.isEmpty()){
            for(int i = 0; i < k-1; i++){
                dq.addLast(dq.getFirst());
                dq.removeFirst();
            }
            v.add(dq.peek());
            dq.removeFirst();
        }
        System.out.print("<");
        for(int i = 0; i < n; i++){
            if(i == n - 1) System.out.print(v.get(i));
            else System.out.print(v.get(i) + ", ");
        }
        System.out.print(">");
    }
}
