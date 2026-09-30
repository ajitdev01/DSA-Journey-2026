class Solution
{
    function islandPerimeter($grid)
    {
        $p = 0;
        $m = count($grid);
        $n = count($grid[0]);

        for ($i = 0; $i < $m; $i++) {
            for ($j = 0; $j < $n; $j++) {

                if (!$grid[$i][$j]) {
                    continue;
                }

                $p += 4;

                if ($i && $grid[$i - 1][$j]) {
                    $p -= 2;
                }

                if ($j && $grid[$i][$j - 1]) {
                    $p -= 2;
                }
            }
        }

        return $p;
    }
}