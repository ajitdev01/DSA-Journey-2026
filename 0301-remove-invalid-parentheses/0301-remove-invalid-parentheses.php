class Solution {

    /**
     * @param String $s
     * @return String[]
     */
    function removeInvalidParentheses($s) {

        $n = strlen($s);

        // Minimum removals required
        $left = 0;
        $right = 0;

        for ($i = 0; $i < $n; $i++) {

            if ($s[$i] === '(') {
                $left++;
            }

            elseif ($s[$i] === ')') {

                if ($left > 0) {
                    $left--;
                } else {
                    $right++;
                }
            }
        }

        $ans = [];
        $path = '';

        $dfs = function (
            $idx,
            $leftRem,
            $rightRem,
            $open
        ) use (
            &$dfs,
            &$s,
            &$path,
            &$ans,
            $n
        ) {

            // Invalid prefix
            if ($open < 0) {
                return;
            }

            // Not enough characters left
            if ($leftRem + $rightRem > $n - $idx) {
                return;
            }

            // Finished
            if ($idx === $n) {

                if (
                    $leftRem === 0 &&
                    $rightRem === 0 &&
                    $open === 0
                ) {
                    $ans[$path] = true;
                }

                return;
            }

            $ch = $s[$idx];

            /*
             * Normal character
             */
            if ($ch !== '(' && $ch !== ')') {

                $path .= $ch;

                $dfs(
                    $idx + 1,
                    $leftRem,
                    $rightRem,
                    $open
                );

                $path = substr($path, 0, -1);

                return;
            }

            /*
             * REMOVE '('
             */
            if ($ch === '(' && $leftRem > 0) {

                $dfs(
                    $idx + 1,
                    $leftRem - 1,
                    $rightRem,
                    $open
                );
            }

            /*
             * REMOVE ')'
             */
            if ($ch === ')' && $rightRem > 0) {

                $dfs(
                    $idx + 1,
                    $leftRem,
                    $rightRem - 1,
                    $open
                );
            }

            /*
             * KEEP '('
             */
            if ($ch === '(') {

                $path .= '(';

                $dfs(
                    $idx + 1,
                    $leftRem,
                    $rightRem,
                    $open + 1
                );

                $path = substr($path, 0, -1);
            }

            /*
             * KEEP ')'
             */
            elseif ($open > 0) {

                $path .= ')';

                $dfs(
                    $idx + 1,
                    $leftRem,
                    $rightRem,
                    $open - 1
                );

                $path = substr($path, 0, -1);
            }
        };

        $dfs(0, $left, $right, 0);

        return array_keys($ans);
    }
}