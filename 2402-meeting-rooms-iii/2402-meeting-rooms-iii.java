class Solution {

    static class Pair {
        long endTime;
        int index;
        Pair(long endTime, int index) {
            this.endTime = endTime;
            this.index = index;
        }
    }

    public int mostBooked(int n, int[][] meetings) {
        Queue<Pair> pq = new PriorityQueue<>((Pair a, Pair b) -> {
            if(a.endTime == b.endTime) return a.index - b.index;
            return (int)(a.endTime - b.endTime);
        });

        Arrays.sort(meetings, (int[] a, int[] b) -> {
            return a[0] - b[0];
        });

        for(int i = 0; i < n; i += 1) {
            pq.add(new Pair(0L, i));
        }


        int[] count = new int[n];

        for(int i = 0; i < n; i += 1) count[i] = 0;

        int m = meetings.length;

        for(int i = 0; i < m; i += 1) {
            
            while(!pq.isEmpty() && pq.peek().endTime < meetings[i][0]) {
                Pair p = pq.poll();
                pq.add(new Pair((long)meetings[i][0], p.index));
            }
            Pair p = pq.poll();
            long endTime = p.endTime;
            int index = p.index;
            int duration = meetings[i][1] - meetings[i][0];
            count[index] += 1;
            
            pq.add(new Pair(Math.max(endTime + duration, meetings[i][1]), index));

        }

        int ans = 0;
        int mx = 0;
        for(int i = 0; i < n; i += 1) {
            if(count[i] > mx) {
                mx = count[i];
                ans = i;
            }
        }

        return ans;


    }
}


/*
    4
    [[18,19],[3,12],[17,19],[2,13],[7,10]]



    start here:

    0

    n = 2
    [[0,10],[1,5],[2,7],[3,4]]

    

    0, 0 | 0, 1

    0, 0
    end + 10 - 0

     0, 1 | 10, 0 

     10, 1 | 10, 0

      max(0 + duration , endTime)


    0, 10
    1, 5
    2, 7
    3, 4

    3
    20
    12
    8
    13

4
[[18,19],[3,12],[17,19],[2,13],[7,10]]


4
2, 13
3, 12
7, 10
17, 19
18, 19

--> 

13, 12, 10, 19





    
    [[1,20],[2,10],[3,5],[4,9],[6,8]]

    1, 20
    2, 10
    3, 5
    4, 9
    6, 8



    <int, int >








*/