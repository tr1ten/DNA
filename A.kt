fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        testcase()
    }
}

fun testcase() {
    val n = readLine()!!.toInt()
    print("1 ")
    for (i in n downTo 2) {
        print("$i ")
    }
    println()
}
        