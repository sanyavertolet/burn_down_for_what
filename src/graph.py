import matplotlib.pyplot as plt
import numpy
import pandas as pd
import seaborn as sns
import os


def read_from_csv(filepath):
    shape = (20 // 2, 2000 // 100)
    raw_data = pd.read_csv(filepath, sep=',', header=None).to_numpy()

    time = numpy.zeros(shape)
    quality = numpy.zeros(shape)

    print(len(raw_data))
    for i in range(len(raw_data)):
        item = raw_data[i]
        time[int(item[0]) // 2 - 1, int(item[1]) // 100 - 1] = item[2]
        quality[int(item[0]) // 2 - 1, int(item[1]) // 100 - 1] = item[3]

    print(quality)
    return time, quality

def read_from_csv_for_research(filepath):
    shape = 8
    raw_data = pd.read_csv(filepath, sep=',', header=None).to_numpy()

    time = numpy.zeros(shape)

    for i in range(len(raw_data)):
        item = raw_data[i]
        time[int(item[2]) - 1] = item[3]

    return time


def show_plot(data_list, show_quality = False):
    x_tick_labels = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800,
                     1900, 2000]
    y_tick_labels = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
    if show_quality:
        fig, axs = plt.subplots(3, 2)
    else:
        fig, axs = plt.subplots(3, 1)
    for i in range(len(data_list)):
        if show_quality:
            for j in range(len(data_list[i]) if show_quality else 1):
                sns.heatmap(data_list[i][j], ax=axs[i, j])
        else:
            sns.heatmap(data_list[i][0], ax=axs[i])
            axs[i].set(xlabel='Jobs', ylabel='Processors')
            axs[i].invert_yaxis()
            axs[i].set_xticks(range(len(x_tick_labels)))
            axs[i].set_xticklabels(x_tick_labels, rotation=45)
            axs[i].set_yticks(range(len(y_tick_labels)))
            axs[i].set_yticklabels(y_tick_labels, rotation=0)

    fig.suptitle("Simulated Annealing")
    plt.subplots_adjust(hspace=0.75)

    if show_quality:
        axs[0, 0].set_title("Boltzmann Time")
        axs[1, 0].set_title("Cauchy Time")
        axs[2, 0].set_title("Mixed Time")
        axs[0, 1].set_title("Boltzmann Quality")
        axs[1, 1].set_title("Cauchy Quality")
        axs[2, 1].set_title("Mixed Quality")
    else:
        axs[0].set_title("Boltzmann Time")
        axs[1].set_title("Cauchy Time")
        axs[2].set_title("Mixed Time")
    plt.show()


def get_files(is_parallel):
    project_dir = os.path.join(os.getcwd(), os.path.pardir)
    csv_path = os.path.join(project_dir, "cmake-build-debug")
    boltzmann = os.path.join(csv_path, "boltzmann.csv" if not is_parallel else "boltzmann-parallel.csv")
    cauchy = os.path.join(csv_path, "cauchy.csv" if not is_parallel else "cauchy-parallel.csv")
    mixed = os.path.join(csv_path, "mixed.csv" if not is_parallel else "mixed-parallel.csv")
    return boltzmann, cauchy, mixed


def get_files_research():
    project_dir = os.path.join(os.getcwd(), os.path.pardir)
    csv_path = os.path.join(project_dir, "cmake-build-debug")
    boltzmann = os.path.join(csv_path, "boltzmann-research.csv")
    cauchy = os.path.join(csv_path, "cauchy-research.csv")
    mixed = os.path.join(csv_path, "mixed-research.csv")
    return boltzmann, cauchy, mixed


def heatmaps():
    boltzmann, cauchy, mixed = get_files(True)

    b_time, b_quality = read_from_csv(boltzmann)
    c_time, c_quality = read_from_csv(cauchy)
    m_time, m_quality = read_from_csv(mixed)

    show_plot([[b_time, b_quality], [c_time, c_quality], [m_time, m_quality]])


def graph():
    boltzmann, cauchy, mixed = get_files_research()
    b_time = read_from_csv_for_research(boltzmann)
    c_time = read_from_csv_for_research(cauchy)
    m_time = read_from_csv_for_research(mixed)

    fig, axs = plt.subplots(3, 1)
    axs[0].set_title("Boltzmann")
    axs[0].plot([1, 2, 3, 4, 5, 6, 7, 8], b_time)
    axs[1].set_title("Cauchy")
    axs[1].plot([1, 2, 3, 4, 5, 6, 7, 8], c_time)
    axs[2].set_title("Mixed")
    axs[2].plot([1, 2, 3, 4, 5, 6, 7, 8], m_time)

    # plt.plot([1, 2, 3, 4, 5, 6, 7, 8], b_time)
    plt.show()

def main(is_heatmap):
    if is_heatmap:
        heatmaps()
    else:
        graph()


if __name__ == "__main__":
    main(False)