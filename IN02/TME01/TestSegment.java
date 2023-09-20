public class TestSegment {
	public static void main( String [] args){
		Segment S1= new Segment(6,8);
		int l1= longueur();
		Segment S2= new Segment(12,5);
		int l2= S2.longueur();
		
		if (l1>l2)
			System.out.println ( "le premier segment est plus long !" );
		else
			System.out.println ( "le deuxieme segment est plus long !" );
	}
}
