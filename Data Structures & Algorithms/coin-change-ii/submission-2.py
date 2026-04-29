import functools

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        @functools.lru_cache(maxsize=None)
        def dfs(i: int, a: int) -> int:
            if i >= len(coins):
                return 0
            d = coins[i]
            total_combos = 0
            while a > 0:
                total_combos += dfs(i + 1, a)
                a -= d
            if a == 0:
                total_combos += 1
            return total_combos
        
        combos_i1 = [0] * (amount + 1)
        for i in reversed(range(len(coins))):
            d = coins[i]
            combos_i = [1] * (amount + 1)
            for a_ in range(1, amount + 1):
                a = a_
                total_combos = 0
                while a > 0:
                    total_combos += combos_i1[a]
                    a -= d
                if a == 0:
                    total_combos += 1
                combos_i[a_] = total_combos
                assert total_combos == dfs(i, a_), f'dfs({i},{a_})'
            #print(combos_i)
            combos_i1 = combos_i
        


        return combos_i1[amount]
        return dfs(0, amount)

