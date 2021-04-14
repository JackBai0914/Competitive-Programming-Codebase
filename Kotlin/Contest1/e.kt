private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var pt = 0
fun deal (gp: Int, n:Int, ) {
  var st = 0
  var ed = n - pt
  while (st != ed) {
    var mid = (st + ed) / 2
    var vl = (if(pt+mid-1<0) 0 else s[pt+mid-1]) - (if(pt-1<0) 0 else s[pt-1])
    if (vl <= gp)
      st = mid
    else
      ed = mid - 1
  }

}

fun main(args: Array<String>) {
  var (n, m) = readInts()
  var lens = readInts()
  var s = IntArray(n)
  s[0] = kens[0]
  for (i in 1 until n)
    s[i] = s[i - 1] + lens[i]




  var q = readInt()
  repeat (q) {
    var arr = readInts()
    var sz = arr[0]
    var b = Array<Pair<Int, Int>>(sz, {i -> Pair(arr[i+1], i)})
    b.sortWith(compareBy({it.first}))
   // println("size ${sz}") 
    pt = 0


    var gp = b[0].first - 1
    deal(gp)
    for (i in 1 until sz) {
      gp = b[i].first - b[i - 1].first - 1
      deal(gp)
    }
    gp = m - b[sz-1].first
    deal(gp)
    println((if(pt==n) "YES" else "NO"))
  }
}
