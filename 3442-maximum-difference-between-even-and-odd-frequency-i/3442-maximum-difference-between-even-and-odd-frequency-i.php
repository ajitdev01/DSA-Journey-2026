class Solution {
    public function maxDifference($s) {
        $freq = [];

        foreach (str_split($s) as $ch) {
            $freq[$ch] = ($freq[$ch] ?? 0) + 1;
        }

        $maxOdd = 0;
        $minEven = PHP_INT_MAX;

        foreach ($freq as $count) {
            if ($count % 2 === 1) {
                $maxOdd = max($maxOdd, $count);
            } else {
                $minEven = min($minEven, $count);
            }
        }

        return $maxOdd - $minEven;
    }
}