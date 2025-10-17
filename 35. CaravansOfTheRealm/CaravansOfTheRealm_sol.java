import java.util.*;

public class WizardCaravanFleets {

    public static int carFleets(int target, int[] position, int[] speed) {
        int n = position.length;
        double[] times = new double[n];

        for (int i = 0; i < n; i++) {
            times[i] = (double)(target - position[i]) / speed[i];
        }

        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> position[b] - position[a]);

        Stack<Double> stack = new Stack<>();

        for (int idx : indices) {
            double time = times[idx];
            if (stack.isEmpty() || time > stack.peek()) {
                stack.push(time);
            }
        }

        return stack.size();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); 

        while (T-- > 0) {
            int n = sc.nextInt();
            int target = sc.nextInt();
            int[] position = new int[n];
            int[] speed = new int[n];

            for (int i = 0; i < n; i++) position[i] = sc.nextInt();
            for (int i = 0; i < n; i++) speed[i] = sc.nextInt();

            System.out.println(carFleets(target, position, speed));
        }
        sc.close();
    }
}
