fun main(args: Array<String>?): Unit {
    val (n, m, d) = readLine()!!.trim().split(' ').map(String::toInt)
    val platforms = readLine()!!.trim().split(' ').map(String::toInt)
    var rest = n - platforms.sum()
    if (rest > (m + 1) * (d - 1)) {
        println("NO")
        return
    }
    val river = IntArray(n){0}
    var idx = 0
    for ((id, p) in platforms.withIndex()) {
        val start = minOf(idx + d - 1, idx + rest)
        for (i in start until start + p) {
            river[i] = id + 1
        }
        rest -= start - idx
        idx = start + p
    }
    println("YES")
    println(river.joinToString(" "))
}