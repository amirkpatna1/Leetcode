class Solution {
    public List<String> summaryRanges(int[] v) {
        List<String> ans = new ArrayList<String>();
        if(v.length == 0) return ans;
        int start = v[0];
        int end = v[0];
        for(int i = 1; i < v.length; i += 1) {
            if(v[i] == v[i - 1] + 1) end = v[i];
            else {
                if(start == end) {
                    ans.add(new String(String.valueOf(start)));
                } else
                    ans.add(new String(String.valueOf(start) + "->" + String.valueOf(end)));
                start = v[i];
                end = v[i];
            }
        }
        if(start == end) {
            ans.add(new String(String.valueOf(start)));
        } else
            ans.add(new String(String.valueOf(start) + "->" + String.valueOf(end)));
        return ans;
    }
}