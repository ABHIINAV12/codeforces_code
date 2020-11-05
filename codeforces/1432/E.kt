import java.util.*
 
private fun min(a : Long , b : Long ) : Long
{
	if(a < b)
		return a;
	else 
		return b;
}

fun main(args: Array<String>) {
    var q = readLine()!!.toLong();
    while(q --> 0)
    {
    	var (n , k) =  readLine()!!.split(" ").map { it.toLong() };
    	var s  = readLine()!!.toMutableList();
    	var loc : MutableList<Long> = ArrayList();
    	var cnt = 0;
    
    	for(i in 0 until n )
    	{
    		if(s[i.toInt()] == '0')
    			{
    				loc.add(i);
    				cnt++;
    			}
    	}
    	for(p in 0 until cnt )
    	{
	   			var x : Long = min(loc[p] - p , k);
    			s[loc[p].toInt()] = '1';
    			s[loc[p].toInt() - x.toInt() ] = '0';
    			k-= x;
    	}
    	println(s.joinToString(separator =""));
    }
    
}