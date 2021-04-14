private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var ans = ArrayList<Long>()
var mp = Array(5050){LongArray(5050){0}}
var sr = LongArray(5050){0}
var sc = LongArray(5050){0}

var cx = 1

var cy = 1
var cans: Long = 0
var l:Long = 0
var r:Long = 0
var u:Long = 0
var d:Long = 0


fun adjust(n: Long, m: Long) {
  while (u + sr[cx] <= d) {
    cans += u + sr[cx] - d
    u += sr[cx]
    d -= sr[cx + 1];
    cx ++
  }
  while (d + sr[cx] <= u) {
    cans += d + sr[cx] - u
    d += sr[cx]
    u -= sr[cx - 1];
    cx --
  }

  while (l + sc[cy] <= r) {
    cans += l + sc[cy] - r
    l += sc[cy]
    r -= sc[cy + 1];
    cy ++
  }
  while (r + sc[cy] <= l) {
    cans += r + sc[cy] - l
    r += sc[cy]
    l -= sc[cy - 1];
    cy --
  }
  ans.add(cans)
}

fun main(args: Array<String>) {
    var (n, m, q) = readLongs()
    for (i in 0 until n) {
      var ins = readLongs()
      for (j in 0 until m) {
        mp[i.toInt() + 1][j.toInt() + 1] = ins[j.toInt()]
        sr[i.toInt() + 1] += mp[i.toInt() + 1][j.toInt() + 1]
        sc[j.toInt() + 1] += mp[i.toInt() + 1][j.toInt() + 1]
        cans += mp[i.toInt() + 1][j.toInt() + 1] * (i + j)
        if (i.toInt() != 0) {
          d += mp[i.toInt() + 1][j.toInt() + 1]
        }
        if (j.toInt() != 0) {
          r += mp[i.toInt() + 1][j.toInt() + 1]
        }
      }
    }
    

    adjust(n, m)

    repeat(q.toInt()) {
      var (a, b, x) = readLongs()
      var del:Long = x - mp[a.toInt()][b.toInt()]
      mp[a.toInt()][b.toInt()] = x
      sr[a.toInt()] += del
      sc[b.toInt()] += del
      if (a < cx)           u += del
      else if (a > cx)      d += del
      if (b < cy)           l += del
      else if (b > cy)      r += del
      cans += del * (maxOf(a - cx, cx - a) + maxOf(b - cy, cy - b))
      adjust(n, m)
    }
    println(ans.joinToString(" "))

}
