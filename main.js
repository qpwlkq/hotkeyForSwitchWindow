const robot = require('robotjs');

// 获取Windows应用程序的窗口标题
const windowTitle = '应用程序的窗口标题';


async function f() {
    // 模拟按下Alt + Tab键切换窗口
    robot.keyTap('tab', ['alt']);

    // 等待一段时间，确保窗口切换完成
    robot.setKeyboardDelay(1000);

    await sleep(10000);
    // // 模拟按下Enter键，将焦点设置到指定的窗口
    // robot.keyTap('enter');
    
    // 模拟输入窗口标题，以便在多个相同标题的窗口中定位目标窗口
    // robot.typeString(windowTitle);
    
    // 模拟按下Enter键，确认窗口选择
    // robot.keyTap('enter');
}


function sleep(ms) {
    console.log("sleep")
    return new Promise((resolve) => setTimeout(resolve, ms));
}

f();