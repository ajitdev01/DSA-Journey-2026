class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $stack = [];

        $pairs = [
            ')' => '(',
            ']' => '[',
            '}' => '{'
        ];

        for ($i = 0; $i < strlen($s); $i++) {
            $char = $s[$i];

            // Opening bracket
            if ($char === '(' || $char === '[' || $char === '{') {
                $stack[] = $char;
            }
            // Closing bracket
            else {
                if (empty($stack) || array_pop($stack) !== $pairs[$char]) {
                    return false;
                }
            }
        }

        return empty($stack);
    }
}