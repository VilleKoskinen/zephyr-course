board_runner_args(openocd --cmd-pre-init "source [find interface/cmsis-dap.cfg]")
board_runner_args(openocd --cmd-pre-init "transport select swd")
board_runner_args(openocd --cmd-pre-init "source [find target/rp2040.cfg]")
board_runner_args(openocd --cmd-pre-init "set_adapter_speed_if_not_set 2000")

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
