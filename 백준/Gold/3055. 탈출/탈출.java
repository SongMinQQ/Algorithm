import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int r, c;
    static int[][] visited = new int[52][52];
    static int[][] visited2 = new int[52][52];
    static char[][] forest = new char[52][52];
    static int destinationX, destinationY;
    static Queue<Pair> q1 = new LinkedList<>();
    static Queue<Pair> q2 = new LinkedList<>();
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static class Pair {
        int y, x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static void fillWater(int y, int x) {
        visited2[y][x] = 1;
        while (!q2.isEmpty()) {
            Pair cur = q2.poll();
            y = cur.y;
            x = cur.x;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                    continue;
                if (visited2[ny][nx] != 0)
                    continue;
                if (forest[ny][nx] == 'X' || forest[ny][nx] == 'S' || forest[ny][nx] == 'D')
                    continue;
                q2.offer(new Pair(ny, nx));
                visited2[ny][nx] = visited2[y][x] + 1;
            }
        }
    }

    static void move(int y, int x) {
        visited[y][x] = 1;
        while (!q1.isEmpty()) {
            Pair cur = q1.poll();
            y = cur.y;
            x = cur.x;
            if (visited2[y][x] == visited[y][x])
                continue;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                    continue;
                if (visited[ny][nx] != 0)
                    continue;
                if (forest[ny][nx] == 'X')
                    continue;
                q1.offer(new Pair(ny, nx));
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        for (int i = 0; i < r; i++) {
            String line = sc.next();
            for (int j = 0; j < c; j++) {
                forest[i][j] = line.charAt(j);
                if (forest[i][j] == 'D') {
                    destinationY = i;
                    destinationX = j;
                }
                if (forest[i][j] == '*') {
                    q2.offer(new Pair(i, j));
                }
                if (forest[i][j] == 'S') {
                    q1.offer(new Pair(i, j));
                }
            }
        }
        if (!q2.isEmpty()) {
            Pair firstWater = q2.peek();
            fillWater(firstWater.y, firstWater.x);
        }
        if (!q1.isEmpty()) {
            Pair firstMove = q1.peek();
            move(firstMove.y, firstMove.x);
        }
        if (visited[destinationY][destinationX] == 0)
            System.out.println("KAKTUS");
        else
            System.out.println(visited[destinationY][destinationX] - 1);
    }
}
