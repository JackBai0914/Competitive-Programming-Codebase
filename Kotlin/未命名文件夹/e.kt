private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles



fun main(args: Array<String>) {
    var (n, m, k) = readInts()
    k --
    var mu = IntArray(n)
    var ans = IntArray(n)

    for (i in 0 until n) {
      mu[i] = 1000000000
    }
    mu[k] = 0

    for (i in 0 until m) {
      var (a, b) = readInts()
      a --
      b --
      //println("$a ${dp[a]} ${c1}")
      //println("$b ${dp[b]} ${c2}")
      var aa = mu[a]
      var bb = mu[b]
      mu[a] = minOf(aa + 1, bb)
      mu[b] = minOf(bb + 1, aa)
    }
    for (i in 0 until n) {
      ans[i] = mu[i]
      if (ans[i] == 1000000000)
        ans[i] = -1
    }
    println(ans.joinToString(" "))

}

