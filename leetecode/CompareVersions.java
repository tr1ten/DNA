class CompareVersions {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int n = Math.min(v1.length, v2.length);
        for (int i = 0; i < n; i++) {
            if(Integer.parseInt(v1[i])<Integer.parseInt(v2[i])){
                return -1;
            }
            else if(Integer.parseInt(v1[i])>Integer.parseInt(v2[i])) return 1;
        }
        if(v1.length==v2.length) return 0;
        else if(v1.length>v2.length){
            for (int i = n; i < v1.length; i++) {
                if(Integer.parseInt(v1[i])>0) return 1;
            }
            return 0;
        }
        else{
            for (int i = n; i < v2.length; i++) {
                if(Integer.parseInt(v2[i])>0) return -1;
            }
            return 0;
        }
    }
    public static void main(String[] args) {
        CompareVersions s = new CompareVersions();
        System.out.println(s.compareVersion("1.01", "1.1.2"));
    }
}