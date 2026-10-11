
class Solution {
    function sumOfSquares($nums) {
        $n = count($nums);
        $ans = 0;

        for ($i = 1; $i <= $n; $i++) {
            if ($n % $i == 0) {
                $ans += $nums[$i - 1] * $nums[$i - 1];
            }
        }

        return $ans;
    }
}
