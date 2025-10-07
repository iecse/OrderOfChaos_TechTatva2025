import java.util.*;

class Solution {
    public int sacredPortal(int[][] realm) {
        int N = realm.length;
        final int DRAW = 0, SPIRIT = 1, SHADOW = 2;

        int[][][] outcome = new int[50][50][3];
        int[][][] options = new int[50][50][3];

        // options[state] : number of neutral moves from this state
        for (int spirit = 0; spirit < N; ++spirit) {
            for (int shadow = 0; shadow < N; ++shadow) {
                options[spirit][shadow][1] = realm[spirit].length;  // Spirit's turn
                options[spirit][shadow][2] = realm[shadow].length;  // Shadow's turn
                for (int x : realm[shadow]) {
                    if (x == 0) { // Shadow cannot enter portal
                        options[spirit][shadow][2]--;
                        break;
                    }
                }
            }
        }

        Queue<int[]> queue = new LinkedList<>();

        // Base cases
        for (int i = 0; i < N; ++i) {
            for (int turn = 1; turn <= 2; ++turn) {
                // Spirit reaches portal
                outcome[0][i][turn] = SPIRIT;
                queue.add(new int[]{0, i, turn, SPIRIT});

                // Shadow catches Spirit
                if (i > 0) {
                    outcome[i][i][turn] = SHADOW;
                    queue.add(new int[]{i, i, turn, SHADOW});
                }
            }
        }

        // Retrograde BFS
        while (!queue.isEmpty()) {
            int[] state = queue.remove();
            int spirit = state[0], shadow = state[1], turn = state[2], result = state[3];

            for (int[] ancestor : ancestors(realm, spirit, shadow, turn)) {
                int s2 = ancestor[0], sh2 = ancestor[1], t2 = ancestor[2];
                if (outcome[s2][sh2][t2] == DRAW) {
                    if (t2 == result) {
                        outcome[s2][sh2][t2] = result;
                        queue.add(new int[]{s2, sh2, t2, result});
                    } else {
                        options[s2][sh2][t2]--;
                        if (options[s2][sh2][t2] == 0) {
                            outcome[s2][sh2][t2] = 3 - t2; // other side wins
                            queue.add(new int[]{s2, sh2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        // Start: Spirit at 1, Shadow at 2, Spirit moves first
        return outcome[1][2][1];
    }

    // Possible ancestors of a state
    public List<int[]> ancestors(int[][] realm, int spirit, int shadow, int turn) {
        List<int[]> res = new ArrayList<>();
        if (turn == 2) { // Shadow just moved -> Spirit turn before
            for (int s2 : realm[spirit]) {
                res.add(new int[]{s2, shadow, 3 - turn});
            }
        } else { // Spirit just moved -> Shadow turn before
            for (int sh2 : realm[shadow]) {
                if (sh2 > 0) { // Shadow cannot go into portal
                    res.add(new int[]{spirit, sh2, 3 - turn});
                }
            }
        }
        return res;
    }
}
