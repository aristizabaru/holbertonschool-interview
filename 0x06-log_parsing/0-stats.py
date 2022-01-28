#!/usr/bin/python3
"""
Compute log of ip address
"""
import sys


if __name__ == "__main__":
    status_codes = {"200": 0,
                    "301": 0,
                    "400": 0,
                    "401": 0,
                    "403": 0,
                    "404": 0,
                    "405": 0,
                    "500": 0}
    counter = 1
    file_size = 0

    def process_line(line_stdin):
        """ parse log line """
        try:
            line = line_stdin.split()
            status_code = line[-2]
            if status_code in status_codes.keys():
                status_codes[status_code] += 1
            return int(line[-1])
        except Exception:
            return 0

    def stats():
        """print result"""
        print("File size: {}".format(file_size))
        for key in sorted(status_codes.keys()):
            if status_codes[key]:
                print("{}: {}".format(key, status_codes[key]))

    try:
        for line in sys.stdin:
            file_size += process_line(line)
            if counter % 10 == 0:
                stats()
            counter += 1
    except KeyboardInterrupt:
        stats()
        raise
    stats()
