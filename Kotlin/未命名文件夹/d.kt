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
        var (n, m) = readInts()

        var e = Array<Pair<Int, Int>>(m, {Pair(0, 0)})
        var ew = IntArray(m)

        
        var mn = IntArray(n)
        for (i in 0 until n)
          mn[i] = 0
       


        for (i in 0 until m) {
          var (a, b, c) = readInts()
          a --
          b --
          e[i] = Pair(a, b)
          ew[i] = c
          mn[a] = maxOf(mn[a], c)
          mn[b] = maxOf(mn[b], c)
        }

        var check = 1

        for (i in 0 until m) {
          var st = e[i].first
          var ed = e[i].second
          var w = ew[i]
          if (w != minOf (mn[st], mn[ed]))
            check = 0
        }

        if (check == 0)
          println("NO")
        else {
          println("YES")
          println(mn.joinToString(" "))
        }
    }
}

