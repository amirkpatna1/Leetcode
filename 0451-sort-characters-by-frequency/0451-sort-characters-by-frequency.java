class Solution {
    public String frequencySort(String s) {
        int n = s.length();
        Character[] arr = new Character[n];
        int[] mp = new int[256];
        for(int i = 0; i < n; i += 1) {
            arr[i] = s.charAt(i);
            mp[s.charAt(i)] += 1;
        }
        Arrays.sort(arr, (Character a, Character b) -> {
            if(mp[a] == mp[b]) return b - a;
            return mp[b] - mp[a];
        });
        // return arr.toString();
        StringBuilder sb = new StringBuilder();
        for(Character c : arr) {
            sb.append(c);
        }
        return sb.toString();
    }
}