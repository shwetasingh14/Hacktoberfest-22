package factorial;

public class fact {
	public static int fact_rec(int n)
	{
		if(n==0)
			return 1;
		else if(n==1)
			return 1;
		else return(n*(fact_rec(n-1)));
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int f= fact_rec(8);
		System.out.println("factorial = " + f );

	}

}
