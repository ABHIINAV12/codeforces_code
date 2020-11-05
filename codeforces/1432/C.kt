fun main( args: Array<String> ) {
    val t = readLine()!!.toInt()
    (1..t).forEach {
        val n = readLine()!!.toInt()
        val s = readLine()!!.split(" ").map { it.toInt() }.sum()
        println( (s - 1) / n + 1 )
    }
}