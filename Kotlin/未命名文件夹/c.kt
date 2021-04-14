private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles



fun main(args: Array<String>) {
    var t = readInt()
    while (t-- >0) {
        var (n, k, x, y) = readLongs();

        var arr = readLongs()
        var b = Array<Pair<Long, Long>>(n.toInt(), {i -> Pair(arr[i], -arr[i])})
        b.sortWith(compareBy({it.second}))

        var sum: Long
        sum = 0
        for (i in 0 until n)
          sum = sum + b[i.toInt()].first.toLong()

        var ans1: Long
        ans1=0
        for (i in 0 until n)
            if (b[i.toInt()].first > k)
                ans1 += x


        var ans: Long
        ans = 0
        var mx = n*k
        var pt = 0
        while (sum > mx) {
          sum = sum - b[pt].first
          ans = ans + x
          pt ++
        }
        ans = ans + y
        println(minOf(ans, ans1))
        
    }
}

