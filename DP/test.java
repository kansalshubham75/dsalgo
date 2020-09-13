public class test{
    public static int mazePathMulti_rec(int sr, int sc, int er, int ec, int[][] dp) {
		if (sr == er && sc == ec) {
			dp[sr][sc] = 1;
			return 1;
		}

		if (dp[sr][sc] != 0) return dp[sr][sc];

		int count = 0;
		for (int jump=1;sr + jump<= er;jump++)
			count += mazePathMulti_rec(sr + jump, sc, er, ec, dp);

		for (int jump=1;sr + jump<= er && sc + jump<= ec;jump++)
			count += mazePathMulti_rec(sr + jump, sc + jump, er, ec, dp);

		for (int jump=1;sc + jump<= ec;jump++)
			count += mazePathMulti_rec(sr, sc + jump, er, ec, dp);

		return dp[sr][sc] = count;
	}


    public static int mazePathMulti_DP(int sr, int sc, int er, int ec, int[][] dp) {
        
        for(sr=er;sr>=0;sr--){
            for(sc=ec;sc>=0;sc--){

                if (sr == er && sc == ec) {
                    dp[sr][sc] = 1;
                    continue;
                }
        
                int count = 0;
                for (int jump=1;sr + jump<= er;jump++)
                    count += dp[sr+jump][sc];
        
                for (int jump=1;sr + jump<= er && sc + jump<= ec;jump++)
                    count += dp[sr+jump][sc+jump];
        
                for (int jump=1;sc + jump<= ec;jump++)
                    count += dp[sr][sc+jump];
        
                dp[sr][sc] = count;
            }
        }

        return dp[0][0];
    }
    
    
	public static void PathSeries() {
		int er = 3;
		int ec = 3;
		int sr = 0;
		int sc = 0;

		int ans = 0;
		int[][] dp = new int[er + 1][ec + 1];
        
        // ans = mazePathHV_rec(sr, sc, er, ec, dp);

        // ans = mazePathMulti_rec(sr, sc, er, ec, dp);
        ans = mazePathMulti_DP(sr, sc, er, ec, dp);

		display2D(dp);
		System.out.println(ans);
    }
    public static void display2D(int[][] arr) {
		for (int[] ar: arr) {
			for (int ele: ar) {
				System.out.print(ele + " ");
			}
			System.out.println();
		}
		System.out.println();
    }
    public static void main(String[] args) {
		PathSeries();
	}
}