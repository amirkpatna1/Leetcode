class Solution {
    public String replaceWords(List<String> v, String s) {
        String[] arr = s.split(" ");
        Set<String> st = new HashSet<>(v);
        StringBuilder res = new StringBuilder();
        for(String ss : arr) {
            StringBuilder sb = new StringBuilder();
            boolean found = false;
            for(char c : ss.toCharArray()) {
                sb.append(c);
                if(st.contains(sb.toString())) {
                    if(!res.isEmpty()) res.append(' ');
                    res.append(sb);
                    found = true;
                    break;
                }
            }
            if(!found) {
                if(!res.isEmpty()) res.append(' ');
                res.append(ss);
            }
            
        }
        return res.toString();
        
    }
}