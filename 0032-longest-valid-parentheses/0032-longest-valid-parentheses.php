class Solution {
    function longestValidParentheses($s) {
        $left = 0;
        $right = 0;
        $ans = 0;

        // Left to Right
        for ($i = 0, $n = strlen($s); $i < $n; $i++) {
            if ($s[$i] === '(') {
                $left++;
            } else {
                $right++;
            }

            if ($left === $right) {
                $ans = max($ans, 2 * $right);
            } elseif ($right > $left) {
                $left = 0;
                $right = 0;
            }
        }

        $left = 0;
        $right = 0;

        // Right to Left
        for ($i = strlen($s) - 1; $i >= 0; $i--) {
            if ($s[$i] === '(') {
                $left++;
            } else {
                $right++;
            }

            if ($left === $right) {
                $ans = max($ans, 2 * $left);
            } elseif ($left > $right) {
                $left = 0;
                $right = 0;
            }
        }

        return $ans;
    }
}