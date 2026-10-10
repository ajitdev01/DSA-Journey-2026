
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        $n = count($nums);
        $st = 0;
        $end = $n - 1;

        while ($st <= $end) {
            $mid = $st + intdiv($end - $st, 2);

            if ($nums[$mid] == $target) {
                return $mid;
            } elseif ($target > $nums[$mid]) {
                $st = $mid + 1;
            } else {
                $end = $mid - 1;
            }
        }

        return -1;
    }
}
