class Solution(object):
    def groupAnagrams(self, strs ):
        rt = dict()
        for x in strs:
            k = "".join(sorted(x))
            if k in rt:
                rt[k].append(x)
            else:
                rt[k] = [x]
        return [v for v in rt.values()]

    """
        def groupAnagrams(self, strs):
            rtable = dict()
            for s in strs:
                local = dict()
                for x in s:
                    if x in local:
                        local[x] += 1
                    else:
                        local[x] = 1
                ss = frozenset(local.items())
                if ss in rtable:
                    rtable[ss].append(s)
                else:
                    rtable[ss] = [s]
            return [val for val in rtable.values()]
    """