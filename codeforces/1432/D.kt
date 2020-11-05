fun main() {
    val chars = "qwertyuiopasdfghjklzxcvbnm"
    val t = readLine()!!.toInt()
    
    repeat(t) {
        val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }
        val s = mutableListOf<Char>()
        for (i in (0 until a)) s += chars[i % b]
        for (i in a until n) s += s[i % a]
        println(s.joinToString(""))
        
    }
}