import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static void hanoi(int cnt, int from, int temp, int to){
        //모든 판을 다 옮긴 경우 종료
        if(cnt == 0) return;
        //현재 기둥에서 맨 아래 판을 뺀 나머지(cnt - 1)들을 임시 기둥에 옮겨 놓기
        hanoi(cnt - 1, from, to, temp);
        //맨 아래 판을 목적 기둥에 옮겨 놓기
//        result.append(' ').append(cnt).append(" : ").append(from).append(" -> ").append(to).append('\n');
        sb.append(from).append(" ").append(to).append('\n');
//        System.out.println(from + " " + to);
        //나머지 판을(cnt - 1)을 목적 기둥(to) 옮겨 놓기
        hanoi(cnt - 1, temp, from, to);
    }
    public static void main(String[] args)throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        int count2 = count;
        BigInteger moves = BigInteger.valueOf(2).pow(count).subtract(BigInteger.ONE);
//        System.out.println(result);
        if(count2 > 20){
            System.out.print(moves);
        }
        else{
            hanoi(count,1,2,3);
            System.out.println(moves);
            System.out.print(sb);
        }
    }
}
