function solve(data) {
    data = data.trim().split('\n');

    const n = Number(data[0]);
    const names = new Set(data.slice(1, n + 1));
    const maxDistance = Number(data[n + 1]);

    const coords = {};
    for (let name of names) {
        const [x, y] = name.split(/\s+/);
        coords[name] = [x, y];
    }

    const [start, finish] = data[n + 2].split(/\s+/);
    const startTown = data[start];
    const finishTown = data[finish];

    let nextStep = [new Set([startTown])];
    let stepsCount = 0;
    names.delete(startTown);

    while (nextStep[stepsCount].size) {
        const prevStepsCount = stepsCount;
        ++stepsCount;
        nextStep.push(new Set());

        for (let from of nextStep[prevStepsCount]) {
            const [fromX, fromY] = coords[from];

            for (let to of names) {
                const [toX, toY] = coords[to];

                if (Math.abs(toX - fromX) + Math.abs(toY - fromY) <= maxDistance) {
                    if (to === finishTown) return stepsCount;

                    nextStep[stepsCount].add(to);
                }
            }
        }

        for (let town of nextStep[stepsCount]) {
            names.delete(town);
        }
    }

    return -1;
}

const fs = require('fs');
const content = fs.readFileSync('../input.txt', 'utf8');
const result = solve(content);
fs.writeFileSync('../output.txt', result + '');
