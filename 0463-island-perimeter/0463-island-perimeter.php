class Solution
{
    public function islandPerimeter($grid)
    {
        $rows = count($grid);
        $cols = count($grid[0]);
        $perimeter = 0;

        for ($r = 0; $r < $rows; $r++) {
            for ($c = 0; $c < $cols; $c++) {

                if ($grid[$r][$c] == 0) {
                    continue;
                }

                // Every land cell has 4 sides
                $perimeter += 4;

                // Shared edge with upper cell
                if ($r > 0 && $grid[$r - 1][$c] == 1) {
                    $perimeter -= 2;
                }

                // Shared edge with left cell
                if ($c > 0 && $grid[$r][$c - 1] == 1) {
                    $perimeter -= 2;
                }
            }
        }

        return $perimeter;
    }
}