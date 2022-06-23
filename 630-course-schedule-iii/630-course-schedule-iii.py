import heapq

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        pq = []
        sum = 0
        for dur, end in sorted(courses, key=lambda c: c[1]):
            sum += dur
            heapq.heappush(pq, -dur)
            if sum > end:
                sum += heapq.heappop(pq)
        return len(pq)
