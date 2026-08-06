
import os

# 只有当环境变量 COVERAGE=1 时才启动 Python 覆盖率收集。
# coverage 模块很重（~80ms），懒加载避免每次测试都付出该导入开销。
if os.environ.get("COVERAGE") == "1":
    import atexit
    import coverage

    # 指定只监控 testcases 目录，并明确报告保存的绝对路径
    cov_file = os.path.abspath("build/coverage/.coverage")
    os.makedirs(os.path.dirname(cov_file), exist_ok=True)

    cov = coverage.Coverage(
        data_file=cov_file,
        source=["testcases"],
        branch=True
    )
    cov.start()

    # 仿真进程退出时自动保存数据并生成网页
    def save_coverage():
        cov.stop()
        cov.save()
        cov.html_report(directory="build/coverage/python_html")
        print(f"\n[Coverage] Python coverage report generated at build/coverage/python_html/index.html")

    atexit.register(save_coverage)


    