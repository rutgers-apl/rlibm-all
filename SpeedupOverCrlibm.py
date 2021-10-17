import matplotlib
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

matplotlib.rcParams['pdf.fonttype'] = 42
matplotlib.rcParams['ps.fonttype'] = 42

overallLabel = ["ln", "log2", "log10", "exp", "sinh", "cosh", "sinpi", "cospi", "avg."]

labels = overallLabel
# Here we have to set up the values
glibcFloatTime = []
rlibmRnoTime = []
againstFloat = []

fileName = ["log.txt", "log2.txt", "log10.txt", "exp.txt", "sinh.txt", "cosh.txt", "sinpi.txt", "cospi.txt"]

for i in range(0, len(fileName)) :
    fp = open("overhead_test/crlibm/" + fileName[i], "r")
    line = fp.readline()
    line = line.split(",")
    glibcFloatTime.append(float(line[0]))
    fp.close()
glibcFloatTime.append(sum(glibcFloatTime))
    
for i in range(0, len(fileName)) :
    fp = open("overhead_test/glibc_rlibm_generic/" + fileName[i], "r")
    line = fp.readline()
    line = line.split(",")
    rlibmRnoTime.append(float(line[0]))
    fp.close()
rlibmRnoTime.append(sum(rlibmRnoTime))

for i in range(0, len(overallLabel)) :
    againstFloat.append(glibcFloatTime[i] / rlibmRnoTime[i])

print(againstFloat)

x = np.arange(len(labels))  # the label locations
width = 0.35  # the width of the bars

fig, ax = plt.subplots()
ax.set_ylim(0, 2.5)
ax.axhline(0.5, color="gray", ls = '--', linewidth = 0.5, zorder = 0)
ax.axhline(1, color="k", ls = '--', linewidth = 1, zorder = 0)
ax.axhline(1.5, color="gray", ls = '--', linewidth = 0.5, zorder = 0)
ax.axhline(2.0, color="k", ls = '--', linewidth = 1, zorder = 0)
rects1 = ax.bar(x, againstFloat, width, color="tab:orange", label='Speedup over float libm', zorder = 100)

# Add some text for labels, title and custom x-axis tick labels, etc.
#plt.xticks(rotation=15, ha="right", rotation_mode="anchor")
ax.set_ylabel('Speedup')
#ax.set_title('Performance speedup')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend(bbox_to_anchor=(-0.1, 0.98, 1.1, 0.2), loc="lower left", mode="expand", ncol=2)
ax.yaxis.set_major_formatter(ticker.FormatStrFormatter('$%.f x$'))

fig.tight_layout()

plt.gcf().set_size_inches(5, 1.2)
plt.savefig('SpeedupOverCrlibm.pdf', bbox_inches='tight', pad_inches = -0.001)
