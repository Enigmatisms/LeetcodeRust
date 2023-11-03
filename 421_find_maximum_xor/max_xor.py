
if __name__ == "__main__":
    nums = [14,70,53,83,49,91,80,92,51,66,70,36]
    len_nums = len(nums)
    max_1 = 0
    max_2 = 0
    max_val = 0

    for i, u in enumerate(nums):
        for j in range(i, len_nums):
            v = nums[j]
            val = u ^ v
            if val > max_val:
                max_val = val
                max_1 = u
                max_2 = v
    print(f"Maximum XOR is {max_val} ({max_val:b}), with u = {max_1} ({max_1:b}), v = {max_2} ({max_2:b})")
    